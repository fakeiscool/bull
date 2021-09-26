<html> 
    <head> 
        <meta charset="utf-8"> 
    </head> 
    <body> 
<?php 
$connection = mysqli_connect("localhost", "root", "", "dbase_pc") 
or die ("Ошибка соединения с сервером"); 
$query = "CREATE TABLE pc (id INT AUTO_INCREMENT, reg_num INT, model_code INT, processor_type VARCHAR(30), 
disk_size INT, memory_size INT, PRIMARY KEY(id))"; 
$result = mysqli_query ($connection, $query) 
or die("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
mysqli_close($connection); 

$connection1 = mysqli_connect("localhost", "root", "", "dbase_pc") 
or die ("Ошибка соединения с сервером"); 
$query1 = "CREATE TABLE sizeset (id INT AUTO_INCREMENT, nums INT, PRIMARY KEY(id))"; 
$result1 = mysqli_query ($connection1, $query1) 
or die("Ошибка при выполнении запроса ".mysqli_errno ($connection1).": ".mysqli_error ($connection1)); 
mysqli_close($connection1); 

echo "Данные добавлены успешно"; 
?> 
</body> 
