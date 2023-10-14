// popup.js

document.addEventListener("DOMContentLoaded", function () {
    // Get references to UI elements
    const startButton = document.getElementById("start-btn");
    const stopButton = document.getElementById("stop-btn");
    const generateReportButton = document.getElementById("generate-report-btn");
    const attendanceStatus = document.getElementById("attendance-status");
    const attendanceCount = document.getElementById("attendance-count");

    // Variable to track attendance
    let isTracking = false;
    let attendance = 0;
    let trackingInterval;

    // Initialize attendance data storage
    const attendanceData = {
        present: 0,
        absent: 0,
    };

    // Event listener for the "Start" button
    startButton.addEventListener("click", function () {
        if (!isTracking) {
            // Start attendance tracking
            isTracking = true;
            attendance = 0;
            attendanceStatus.innerText = "Tracking...";
            attendanceCount.innerText = attendance; // Reset attendance count

            // Track attendance periodically using setInterval
            trackingInterval = setInterval(function () {
                if (isTracking) {
                    // Simulate user activity (replace with your actual logic)
                    const isUserActive = Math.random() < 0.8; // 80% chance of being active

                    if (isUserActive) {
                        attendance++;
                        attendanceData.present++;
                    } else {
                        attendanceData.absent++;
                    }

                    attendanceCount.innerText = attendance;
                }
            }, 1000); // Update every 1 second (adjust as needed)
        }
    });

    // Event listener for the "Stop" button
    stopButton.addEventListener("click", function () {
        if (isTracking) {
            // Stop attendance tracking
            isTracking = false;
            clearInterval(trackingInterval);
            attendanceStatus.innerText = "Attendance Stopped";
        }
    });

    // Event listener for the "Generate Report" button
    generateReportButton.addEventListener("click", function () {
        // Calculate attendance percentage
        const totalAttendees = attendanceData.present + attendanceData.absent;
        const attendancePercentage =
            (attendanceData.present / totalAttendees) * 100;

        // Display the attendance report in a popup alert (replace with your UI)
        alert(`Attendance Percentage: ${attendancePercentage.toFixed(2)}%`);
    });
});
