import numpy as np
import matplotlib.pyplot as plt
from numpy.linalg import svd
from PIL import Image

class ImageCompressor:
    def __init__(self, image_path):
        self.image_path = image_path
        self.image = np.asarray(Image.open(image_path))

    def compress(self, k):
        k = int((k / 100) * min(self.image.shape[0], self.image.shape[1]))

        r = self.image[:, :, 0]
        g = self.image[:, :, 1]
        b = self.image[:, :, 2]

        ur, sr, vr = svd(r, full_matrices=False)
        ug, sg, vg = svd(g, full_matrices=False)
        ub, sb, vb = svd(b, full_matrices=False)

        rr = np.dot(ur[:, :k], np.dot(np.diag(sr[:k]), vr[:k, :]))
        rg = np.dot(ug[:, :k], np.dot(np.diag(sg[:k]), vg[:k, :]))
        rb = np.dot(ub[:, :k], np.dot(np.diag(sb[:k]), vb[:k, :]))

        rimg = np.zeros(self.image.shape)
        rimg[:, :, 0] = rr
        rimg[:, :, 1] = rg
        rimg[:, :, 2] = rb

        for ind1, row in enumerate(rimg):
            for ind2, col in enumerate(row):
                for ind3, value in enumerate(col):
                    if value < 0:
                        rimg[ind1, ind2, ind3] = abs(value)
                    if value > 255:
                        rimg[ind1, ind2, ind3] = 255

        self.compressed_image = rimg.astype(np.uint8)

    def display_compressed_image(self, title="Compressed Image"):
        plt.title(title)
        plt.imshow(self.compressed_image)
        plt.axis('off')
        plt.show()

    def save_compressed_image(self, output_path):
        self.compressed_image = Image.fromarray(self.compressed_image)
        self.compressed_image.save(output_path)


# Example usage:
# percent = [5, 10, 25, 50, 75, 90]
# for i in range(6):
#     compressor = ImageCompressor('compressed-90.jpg')
#     compressor.compress(percent[i])
#     compressor.save_compressed_image('compressed-90-{}.jpg'.format(percent[i]))
    
# compressor.display_compressed_image()

compressor = ImageCompressor('0553227.png')
compressor.compress(100)
compressor.save_compressed_image('comp.png')