import numpy as np
from matplotlib.image import imread
import matplotlib.pyplot as plt
import cv2
from sklearn.decomposition import IncrementalPCA

image_raw = imread("exam.jpg")
blue,green,red = cv2.split(image_raw)

df_blue = blue/255
df_green = green/255
df_red = red/255

def compress(percent):
    k = int((percent / 100) * min(image_raw.shape[0], image_raw.shape[1]))

    ipca_b = IncrementalPCA(n_components=k)
    ipca_g = IncrementalPCA(n_components=k)
    ipca_r = IncrementalPCA(n_components=k)

    rec_blue = ipca_b.inverse_transform(ipca_b.fit_transform(df_blue))
    rec_green = ipca_g.inverse_transform(ipca_g.fit_transform(df_green))
    rec_red = ipca_r.inverse_transform(ipca_r.fit_transform(df_red))

    rec_image = np.dstack((rec_blue, rec_green, rec_red))

    plt.imshow(rec_image)
    plt.title("Preserved: " + str(percent) + "%")

# percents = [10, 25, 50, 75, 90, 100]
# plt.figure(figsize=[16, 9])

# for i in range(6):
#     plt.subplot(2, 3, i+1)
#     compress(percents[i])

# plt.subplots_adjust(wspace=0.2, hspace=0.2)
# plt.show()

# print(image_sum.max())
# print(n_sample)
# for i in range(6):
#     k = int((percents[i] * 2 / 300) * n_sample)
#     p = int((percents[i] / 100) * n_sample)
#     print(f"{k} ------ {p}")

compress(1)
plt.imsave()
