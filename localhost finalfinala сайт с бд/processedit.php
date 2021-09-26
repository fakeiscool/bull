<html>  
<HEAD> 
    <title>Изменение данных оборудования</title> 
    <meta charset="utf-8"> 
</HEAD>  
<h2 align="center">Результат изменения данных оборудования</h2> 
<body > 
<?php 

	$id=$_POST['id']; 
	$reg_numedit=$_POST['reg_numadd']; 
	$model_codeedit = $_POST['model_codeadd'];
	$processor_typeedit = $_POST['processor_typeadd'];
	$disk_sizeedit = $_POST['disk_sizeadd'];
	$memory_sizeedit = $_POST['memory_sizeadd'];
	
	require 'fdata.php';
	$error = testdata($reg_numedit,$model_codeedit, $processor_typeedit,$disk_sizeedit, $memory_sizeedit);
	
	if ($error !='Ошибка: ')  {
		echo "<center style=\"color:red\">$error<center>";
		echo '<form action="phpdatatable.php" method="post">'; 
		echo '<input  type="hidden"  name="id"  value="'.$id.'">';  
		echo '<input align="center" type="submit" value="Вернуться к изменениям">'; 
		echo '</form>';
	}
	
	else{
		$connection=mysqli_connect("localhost", "root", "", "dbase_pc") 
		or die("Ошибка соединения с сервером"); 
		
		$query = "UPDATE pc SET  
							reg_num='$reg_numedit', 
							model_code='$model_codeedit',
							processor_type='$processor_typeedit',
							disk_size='$disk_sizeedit',
							memory_size='$memory_sizeedit'
							WHERE id='$id'"; 							
		$result = mysqli_query($connection, $query) 
		or  die  ("Ошибка  при  выполнении  запроса ".mysqli_errno ($connection).": ".mysqli_error 
	($connection)) ; 


		if($result) echo "Данные изменены"; 
		if(!$result) echo "Ошибка изменения данных"; 
		echo "<p><a href='index.php'>Список оборудования</a>";
		mysqli_close($connection); 
	}
      
	

?> 
</body> 
</html> 
