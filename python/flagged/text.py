import pyttsx3

def get_user_input():
    message = input("Enter a message: ")
    return message

def speak_message(message):
    engine = pyttsx3.init()
    engine.say(message)
    engine.runAndWait()

def main():
    user_message = get_user_input()
    speak_message(user_message)

if __name__ == "__main__":
    main()
