<?php
	$connection = mysqli_connect("localhost","root","");
	$db = mysqli_select_db($connection,"sms");
	$query = "update students set name='$_POST[name]',father_name='$_POST[father_name]',course='$_POST[course]',section='$_POST[section]',mobile='$_POST[mobile]',email='$_POST[email]',password='$_POST[password]' where roll_no = $_POST[roll_no]";
	$query_run = mysqli_query($connection,$query);
?>
<script type="text/javascript">
	alert("Details edited successfully.");
	window.location.href = "admin_dashboard.php";
</script>
