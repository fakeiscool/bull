<html>  
<HEAD> 
    <title>Удаление данных оборудования</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Результат изменения данных оборудования</h2> 
<body > 
<?php 
	$id=$_POST['id'];
	$connection=mysqli_connect("localhost", "root", "", "dbase_pc") 
    or die("Ошибка соединения с сервером"); 
	$query = "DELETE FROM pc  
                WHERE id='$id'"; 
				
	$result = mysqli_query($connection, $query) 
    or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error 
($connection)) ; 

	if($result) echo "Данные о оборудования удалены"; 
	if(!$result) echo "Ошибка удаления данных"; 
	echo "<p><a href='index.php'>Список оборудования</a>"; 
	
mysqli_close($connection); 
?> 
</body> 
</html> 	