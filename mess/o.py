import cv2

# Load the pre-trained face detection classifier
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Initialize variables
frame_count_without_face = 0
threshold_frame_count = 10  # Adjust this threshold as needed

# Initialize the video capture
cap = cv2.VideoCapture(0)  # Use 0 for the default camera, or specify the camera index

while True:
    # Read a frame from the video capture
    ret, frame = cap.read()
    
    if not ret:
        break

    # Convert the frame to grayscale for face detection
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces in the frame
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # If faces are detected, reset the frame count
    if len(faces) > 0:
        frame_count_without_face = 0
    else:
        frame_count_without_face += 1

    # Check for inattentiveness
    if frame_count_without_face > threshold_frame_count:
        # Send a message to the host using the platform's API
        send_message_to_host("Participant is not attending the meet properly")

    # Draw rectangles around the detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

    # Display the frame
    cv2.imshow('Face Detection', frame)

    # Break the loop when the 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture and close the OpenCV window
cap.release()
cv2.destroyAllWindows()

# Function to send a message to the host (you need to implement this using the meeting platform's API)
def send_message_to_host(message):
    # Use the meeting platform's API to send the message to the host
    print(message)  # Replace this with your API code
