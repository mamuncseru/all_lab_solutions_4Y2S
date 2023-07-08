import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
import cv2
import os

# Create a 200x200 binary image
image = np.zeros((200, 200), dtype=np.uint8)
image[:, 100:] = 255  # Make half of the image white (255)

# Save the binary image
cv2.imwrite('binary_image.png', image)

# Display the binary image
plt.imshow(image, cmap='gray', vmin=0, vmax=255)
plt.title('Original Binary Image')
plt.show()

def run_length_encode(input_array):
    # Flatten the array in column-major order
    flattened = input_array.flatten(order='F')

    # Run length encoding
    values, counts = np.unique(flattened, return_counts=True)
    encoded_data = np.array([val for pair in zip(values, counts) for val in pair])

    return encoded_data

def run_length_decode(input_array):
    # Run length decoding
    decoded_data = np.repeat(input_array[::2], input_array[1::2])

    # Reshape the array to its original shape in column-major order
    decoded_data = decoded_data.reshape((200, 200), order='F')

    return decoded_data


# Encode the image
encoded_image = run_length_encode(image)

# Save the encoded image as a numpy array file
np.save('encoded_image.npy', encoded_image)

# Decode the image
decoded_image = run_length_decode(encoded_image)

# Save the decoded image
cv2.imwrite('decoded_image.png', decoded_image)

# Display the decoded image
plt.imshow(decoded_image, cmap='gray', vmin=0, vmax=255)
plt.title('Decoded Image')
plt.show()


print("Original binary image file size: ", os.stat('binary_image.png').st_size, "bytes")
print("Encoded image file size: ", os.stat('encoded_image.npy').st_size, "bytes")
print("Decoded image file size: ", os.stat('decoded_image.png').st_size, "bytes")
