<?php

    $connection = mysqli_connect("localhost","root","");
    $db = mysqli_select_db($connection,"sms");
    // $total_marks = $_POST['Web Development'] + $_POST['Compiler Design'] + $_POST['Image Processing'];
    // $percentage = ($total_marks/300)*100;
    // $query = "insert into marks values('',$_POST[Web Development],$_POST[Complier Design],$_POST[Image Processing],'')";
    
    $s_no=$_POST['s_no'];
    $name=$_POST['Name'];
	$web=$_POST['Web_Development'];
	$compiler=$_POST['Compiler_Design'];
	$image=$_POST['Image_Processing'];
					
	$total_marks = $web + $compiler + $image;
	$percentage = ($total_marks/300)*100;
    
    $query="INSERT INTO marks VALUES ('$s_no','$name','$web','$compiler','$image','$percentage')";
    // $query="insert into marks values($s_no,$web,$compiler,$image,$percentage)";
    $query_run= mysqli_query ($connection,$query);
?>
<script type="text/javascript">
	alert("Marks added successfully.");
	window.location.href = "admin_dashboard.php";
</script>