# Importing the lorem module
import lorem

# Create a text file with diverse text
with open('file3.txt', 'w') as file:
    # Generate 100 paragraphs of lorem ipsum text
    for _ in range(50):
        file.write(lorem.paragraph() + '\n')
