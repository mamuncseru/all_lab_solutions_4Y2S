import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
from scipy.fftpack import dct, idct

# Function to perform 2D DCT
def dct2(array):
    return dct(dct(array.T, norm='ortho').T, norm='ortho')

# Function to perform 2D IDCT
def idct2(array):
    return idct(idct(array.T, norm='ortho').T, norm='ortho')

# Load image
image = Image.open('gray_image.png').convert('L')

# Resize image to 16x16
image = image.resize((16, 16), Image.LANCZOS)

# Convert image data to numpy array
image_data = np.array(image)

# Perform 2D DCT
dct_result = dct2(image_data)

# Perform 2D IDCT
idct_result = idct2(dct_result)

# Clamp values to [0, 255]
idct_result = np.clip(idct_result, 0, 255)

# Convert float IDCT result to uint8 for visualization
idct_result = idct_result.astype('uint8')

# Plot original image
plt.figure()
plt.imshow(image_data, cmap='gray')
plt.title('Original Image')
plt.savefig('orig.png')

# Plot DCT result
plt.figure()
plt.imshow(np.log(abs(dct_result)), cmap='gray')  # We're using log scale for better visualization
plt.title('DCT Result')
plt.savefig('dct.png')

# Plot IDCT result
plt.figure()
plt.imshow(idct_result, cmap='gray')
plt.title('IDCT Result')
plt.savefig('idct.png')

plt.show()
