from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

# Create a 16x16 image
image = Image.new('L', (16, 16))

# Generate random gray values
np.random.seed(0)  # for reproducibility
gray_values = np.random.randint(0, 256, (16, 16))

# Fill the image with gray values
for i in range(16):
    for j in range(16):
        image.putpixel((j, i), int(gray_values[i, j]))

# Save the image
image.save('gray_image.png')

# Display the image
plt.imshow(gray_values, cmap='gray')
plt.title('Generated Gray Image')
plt.show()
