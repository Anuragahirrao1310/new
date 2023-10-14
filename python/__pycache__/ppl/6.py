# Function to count word frequency in a string
def count_word_frequency(text):
    words = text.split()
    word_frequency = {}

    for word in words:
    
        word = word.strip('.,!?"\'').lower()
        if word in word_frequency:
            word_frequency[word] += 1
        else:
            word_frequency[word] = 1

    return word_frequency

input_string = "This is a sample string. It contains sample words, and this is an example."

frequency_dict = count_word_frequency(input_string)

for word, count in frequency_dict.items():
    print(f"{word}: {count}")
