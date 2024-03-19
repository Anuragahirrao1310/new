from gtts import gTTS
import os

def get_user_input():
    message = input("Enter a message: ")
    return message


def speak_message(message, gender='female'):
    tts = gTTS(text=message, lang='en', slow=False)
    
    # Choose the voice gender
    if gender == 'male':
        tts.save("output.mp3")
    elif gender == 'female':
        tts.save("output_female.mp3")

    # Play the generated audio file
    os.system("start output.mp3") if gender == 'male' else os.system("start output_female.mp3")

def main():
    user_message = get_user_input()
    gender = input("Enter voice gender (male/female): ").lower()
    speak_message(user_message, gender)

if __name__ == "__main__":
    main()
