<html>  
<HEAD> 
    <title>Добавление размеров</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Результат добавления размера</h2> 
<body >
<?php 
	$sizeadd = $_POST['sizethatadds'];
	
	$connection = mysqli_connect("localhost", "root", "", "dbase_pc") 
	or die ("Ошибка соединения с сервером"); 
	$query = "INSERT INTO sizeset (nums) VALUES ('$sizeadd')";
	$result = mysqli_query ($connection, $query) 
	or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 

	if($result) echo "Данные сохранены"; 
	if(!$result) echo "Ошибка сохранения данных"; 
	echo "<p><a href='grupedit.php'>Список размеров памяти</a>";  
	mysqli_close($connection); 
 
?> 
</body> 
</html> 
