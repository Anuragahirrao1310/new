<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['Name'];
    $email = $_POST['Email'];
    $message = $_POST['Message'];
    $to = "anuragahirrao1310@gmail.com";
    $subject = "New Message from Contact Form";
    $body = "Name: $name\nEmail: $email\nMessage: $message";
    $headers = "From: $email";

    if (mail($to, $subject, $body, $headers)) {
        echo "Message sent successfully!";
    } else {
        echo "Oops! Something went wrong.";
    }
}
?>
