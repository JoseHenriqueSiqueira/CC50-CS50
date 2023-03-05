def readability():
    # Get input string to analyze
    input_string = input("Text: ")

    letter_count = 0
    word_count = 1
    sentence_count = 0

    # Count letters, words, and sentences in the input string.
    # Assume that any character A-Z and a-z is a letter.
    for i in range(len(input_string)):
        if input_string[i].isalpha():
            letter_count += 1

        # Any sequence of characters separated by space is a word.
        if input_string[i] == ' ':
            word_count += 1

        # If a period, exclamation point, or question mark is encountered, increment sentence count.
        if input_string[i] == '.' or input_string[i] == '!' or input_string[i] == '?':
            sentence_count += 1

    # Calculate the reading index grade level of the input text.
    L = (letter_count / word_count) * 100
    S = (sentence_count / word_count) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Print the reading index grade level of the input text.
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

if __name__ == "__main__":
    readability()





