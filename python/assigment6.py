def count_word_frequency(text):
    words = text.lower().split()  # Convert to lowercase and split into words
    word_frequency = {}  # Dictionary to store word frequencies
    
    for word in words:
        # Remove punctuation from the word
        word = word.strip(".,!?\"'()[]{}:;-")
        
        if word:  # Check if the word is not empty after removing punctuation
            if word in word_frequency:
                word_frequency[word] += 1
            else:
                word_frequency[word] = 1
    
    return word_frequency

# Example string
input_string = "This is a sample string, and this is just a sample."

word_frequency = count_word_frequency(input_string)

# Display the word frequencies
for word, frequency in word_frequency.items():
    print(f"'{word}': {frequency}")

