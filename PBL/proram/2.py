import cv2
import time  # Import the time module

# Load the pre-trained face detection classifier
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Initialize variables
frame_count_without_face = 0
threshold_frame_count = 10  # Threshold for inattentiveness in frames (adjust as needed)
attention_lost_time = None  # Initialize the time when attention was lost

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

    # If faces are detected, reset the frame count and the attention_lost_time
    if len(faces) > 0:
        frame_count_without_face = 0
        attention_lost_time = None
    else:
        frame_count_without_face += 1
        # Check if attention has been lost for more than 10 seconds
        if frame_count_without_face > threshold_frame_count:
            if attention_lost_time is None:
                attention_lost_time = time.time()
            else:
                elapsed_time = time.time() - attention_lost_time
                if elapsed_time > 10:
                    # Display a warning message
                    cv2.putText(frame, "Pay Attention!", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    
        frame = cv2.flip(frame, 1)


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
