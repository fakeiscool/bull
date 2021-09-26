<html>  
<HEAD> 
    <title>Добавление клиента</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Результат добавления клиента</h2> 
<body >
<?php 
	
	
	$reg_num = $_POST['reg_num'];
	$model_code = $_POST['model_code'];
	$processor_type = $_POST['processor_type'];
	$memory_size = $_POST['memory_sizebd'];
	$disk_size = $_POST['disk_sizebd'];

	
	require 'fdata.php';
	$error = testdata($reg_num, $model_code, $processor_type, $memory_size, $disk_size);
	
	
	if ($error !='Ошибка: ')  {
		echo "<center style=\"color:red\">$error<center>";
		echo "<p><a href='objectadd.php'>Добавить оборудование</a>";
	}
	else {
		$connection = mysqli_connect("localhost", "root", "", "dbase_pc") 
		or die ("Ошибка соединения с сервером"); 
		$query = "INSERT INTO pc (reg_num, model_code, processor_type, disk_size, memory_size) VALUES ('$reg_num', '$model_code', '$processor_type', '$disk_size', '$memory_size')";
		$result = mysqli_query ($connection, $query) 
		or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 

		if($result) echo "Данные сохранены"; 
		if(!$result) echo "Ошибка сохранения данных"; 
		echo "<p><a href='index.php'>Список оборудования</a>";  
		mysqli_close($connection); 
	} 
?> 
</body> 
</html> 
