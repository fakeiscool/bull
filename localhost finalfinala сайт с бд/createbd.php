<html> 
    <head> 
        <meta charset="utf-8"> 
    </head> 
    <body> 
<?php 
$connection = mysqli_connect("localhost", "root", "") 
or die ("Ошибка соединения с сервером"); 
// создаем базу данных с именем dbase_pc 
$query="CREATE DATABASE dbase_pc"; 
$result = mysqli_query ($connection, $query) 
or die("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
$db = mysqli_select_db($connection, "dbase_pc") 
or die ("Ошибка при выборе базы данных ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
echo "База данных 'dbase_pc' успешно создана"; 
mysqli_close($connection); 
?> 
</body> 
</html> 
