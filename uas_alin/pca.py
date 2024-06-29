import numpy as np
from matplotlib.image import imread
import matplotlib.pyplot as plt
import cv2
from PIL import Image
from sklearn.decomposition import IncrementalPCA

class ImageCompressor:
    def __init__(self, image_path):
        self.image_path = image_path
        self.image_raw = imread(image_path)
        self.image = np.asarray(Image.open(image_path))

    def compress(self, percent):
        self.alpha = None

        if self.image_raw.shape[2] == 4: 
            self.alpha = self.image_raw[:, :, 3] / 255.0
            self.image_raw = self.image_raw[:, :, :3]
        self.blue, self.green, self.red = cv2.split(self.image_raw)
        self.df_blue = self.blue / 255
        self.df_green = self.green / 255
        self.df_red = self.red / 255

        k = int((percent / 100) * min(self.image_raw.shape[0], self.image_raw.shape[1]))

        ipca_b = IncrementalPCA(n_components=k)
        ipca_g = IncrementalPCA(n_components=k)
        ipca_r = IncrementalPCA(n_components=k)

        rec_blue = ipca_b.inverse_transform(ipca_b.fit_transform(self.df_blue))
        rec_green = ipca_g.inverse_transform(ipca_g.fit_transform(self.df_green))
        rec_red = ipca_r.inverse_transform(ipca_r.fit_transform(self.df_red))

        self.rec_image = np.dstack((rec_blue, rec_green, rec_red))

        if self.alpha is not None:  # Add alpha channel back
            self.rec_image = np.dstack((self.rec_image, self.alpha))


    def save(self, output_path):
        self.rec_image = Image.fromarray((self.rec_image*255).astype(np.uint8))
        self.rec_image.save(output_path)


compressor = ImageCompressor('0553227.png')
compressor.compress(100)
compressor.save('hm.png')