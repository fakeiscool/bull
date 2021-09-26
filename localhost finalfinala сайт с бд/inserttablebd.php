<html> 
    <head> 
        <meta charset="utf-8"> 
    </head> 
    <body> 
<?php
$connection = mysqli_connect("localhost", "root", "", "dbase_pc") 
or die ("Ошибка соединения с сервером"); 
$query = "INSERT INTO pc (reg_num, model_code, processor_type, disk_size, memory_size) VALUES ('123', '228133', 'pog', '2048', '2048')"; 
$result = mysqli_query ($connection, $query) 
or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
$query = "INSERT INTO pc (reg_num, model_code, processor_type, disk_size, memory_size) VALUES ('321', '999999', 'pogger', '16384', '4096')"; 
$result = mysqli_query ($connection, $query) 
or die ("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
$query = "INSERT INTO pc (reg_num, model_code, processor_type, disk_size, memory_size) VALUES ('777', '383838', 'pepega', '515', '256')"; 
$result = mysqli_query ($connection, $query) 
or die("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
$query = "INSERT INTO sizeset (nums) VALUES ('512'),('1024'),('2048'),('4096'),('8192'),('16384'),('32768')"; 
$result = mysqli_query ($connection, $query) 
or die("Ошибка при выполнении запроса ".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
echo "Данные добавлены успешно"; 
mysqli_close($connection); 

?> 
</body> 
</html> 