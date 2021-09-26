<html>  
<HEAD> 
    <title>Удаление размера</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Результат удаления</h2> 
<body > 
<?php 
	$id=$_POST['id'];
	$memorygroupdels=$_POST['memorygroupdel'];
	$connection=mysqli_connect("localhost", "root", "", "dbase_pc") 
    or die("Ошибка соединения с сервером");

	$query2 = "DELETE FROM pc WHERE memory_size='$id'";
	$result = mysqli_query($connection, $query2) 
    or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error 
	($connection)) ;


	$query = "DELETE FROM sizeset  
                WHERE id='$id'";
	$result = mysqli_query($connection, $query) 
    or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error 
($connection)) ; 

	if($result) echo "Размер удален"; 
	if(!$result) echo "Ошибка удаления данных"; 
	echo "<p><a href='grupedit.php'>Редактировать размер памяти</a>"; 
	
mysqli_close($connection); 
?> 
</body> 
</html> 	