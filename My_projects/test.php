<!-- <?php
// Database connection details
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "sms";

// Create a connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve the input data from the form
    $rollNumber = $_POST["s_rno"];

    // Query the database to retrieve the marks data
    $sql = "SELECT * FROM marks WHERE s_no = '$rollNumber'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        // Display the result
        echo "<table>";
        echo "<tr><th>Subject</th><th>Marks</th></tr>";

        while ($row = $result->fetch_assoc()) {
            echo "<tr><td>" . $row["s_no"] . " w=".$row["Web Development"]. " c=".$row["Compiler Design"]." i=". $row["Image Processing"]. " p=".$row["percentage"] ."? "   . "</td></tr>";
        }

        echo "</table>";
    } else {
        echo "No marks found for the given roll number.";
    }
}

// Close the database connection
$conn->close();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Marks</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #F4F4F4;
        }

        .container {
            width: 400px;
            margin: 0 auto;
            padding: 20px;
            background-color: #FFFFFF;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        }

        .container h2 {
            text-align: center;
        }

        .result-table {
            width: 100%;
            margin-top: 20px;
            border-collapse: collapse;
        }

        .result-table th, .result-table td {
            padding: 8px;
            text-align: left;
        }

        .result-table th {
            background-color: #F5F5F5;
        }
    </style>
</head>
<body>
    <h2>Student Marks</h2>
    <form method="post" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
        <label for="s_rno">Roll Number:</label>
        <input type="text" name="s_rno" id="s_rno" required><br><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html> -->

<?php
// Database connection details
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "sms";

// Create a connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve the input data from the form
    $rollNumber = $_POST["s_rno"];

    // Query the database to retrieve the marks data
    $sql = "SELECT * FROM marks WHERE s_no = '$rollNumber'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        // Display the result
        echo "<table class='result-table'>";
        echo "<tr><th>Subject</th><th>Marks</th></tr>";

        while ($row = $result->fetch_assoc()) {
            echo "<tr><td>" . $row["s_no"] . "</td><td>" . $row["Web Development"] . "</td></tr>";
            echo "<tr><td></td><td>" . $row["Compiler Design"] . "</td></tr>";
            echo "<tr><td></td><td>" . $row["Image Processing"] . "</td></tr>";
            echo "<tr><td></td><td>" . $row["percentage"] . "</td></tr>";
        }

        echo "</table>";
    } else {
        echo "No marks found for the given roll number.";
    }
}

// Close the database connection
$conn->close();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Marks</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #F4F4F4;
        }

        .container {
            width: 400px;
            margin: 0 auto;
            padding: 20px;
            background-color: #FFFFFF;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        }

        .container h2 {
            text-align: center;
        }

        .result-table {
            width: 100%;
            margin-top: 20px;
            border-collapse: collapse;
        }

        .result-table th, .result-table td {
            padding: 8px;
            text-align: left;
        }

        .result-table th {
            background-color: #F5F5F5;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Student Marks</h2>
        <form method="post" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
            <label for="s_rno">Roll Number:</label>
            <input type="text" name="s_rno" id="s_rno" required><br><br>
            <input type="submit" value="Submit">
        </form>

        <?php if ($_SERVER["REQUEST_METHOD"] == "POST" && $result->num_rows > 0): ?>
            <h3>Result:</h3>
            <table class="result-table">
                <tr>
                    <!-- <th>Subject</th>
                    <th>Marks</th> -->
                </tr>
                <!-- Result rows dynamically generated above -->
            </table>
        <?php endif; ?>
    </div>
</body>
</html>
