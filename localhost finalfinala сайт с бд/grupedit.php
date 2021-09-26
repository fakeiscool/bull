<html> 
<head> 
<title>Редактирование размеров памяти</title> 
<meta charset="utf-8"> 
</head> 
<body> 
<h1>Размеры памяти</h1> 
 
<?php 
    $connection=mysqli_connect("localhost", "root", "", "dbase_pc") or die("Ошибка соединения с сервером"); 
    $query = "SELECT * FROM sizeset";  
    $result  =  mysqli_query  ($connection, $query) or die ("Ошибка  при  выполнении  запроса".mysqli_errno ($connection).": ".mysqli_error ($connection)); 
  echo '<table class="lighting" border=1>';  
  echo '<tr class="up_row"><th>№</th>';  
  echo '<th>Размеры памяти</th>';  
  echo '<th/>';
$i=1; 
while ($row = mysqli_fetch_array ($result))  
  { 
    echo '<tr><td>'; 
    echo $i; 
    echo '</td><td>'.$row['nums'];  
    echo '</td><td>'; 
    echo '<form action="processdelgroup.php" method="post">'; 
    echo '<input  type="hidden"  name="id"  value="'.$row['id'].'">';  
	echo '<input  type="hidden"  name="memorygroupdel"  value="'.$row['nums'].'">'; 
    echo '<input type="submit" name="delgr" value="Удалить">'; 
    echo '</form>'; 
    echo '</td>'; 
    echo '</tr>'; 
    $i++; 
     
  } 
  echo "</table>";   
mysqli_close($connection); 
?> 

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script> 

 <style type="text/css"> 
 .lighting { width: 100%; border-collapse: collapse; border: 2px solid #000000; } 
 .lighting tr { text-align: center; font-weight: bold; line-height: 2; } 
 .lighting tr td { border: 1px solid #503030; } 
 .lighting .up_row { background-color: #6E6E6E; color: #FFFFFF; }
 .lighting_col { background-color: #D4D4D4; } 
 .lighting_cell { background-color: #667E96; color: #FFFFFF; } 
</style>

<script type="text/javascript"> 
$(document).ready(function(){ 
$(".lighting td").on("mouseenter mouseleave", function(){ 
    if ($(this).parents(".lighting tr").attr("class")!="up_row") { 
        var td_index=$(this).index(); 
        $(this).parents("tr").toggleClass("lighting_col"); 
        $(this).parents(".lighting").find("tr:not(.up_row)").each(function(){ 
            $("td:eq("+td_index + ")",this).toggleClass("lighting_col"); 
        }); 
        $(this).toggleClass("lighting_cell"); 
    } 
}); 
}); 
</script> 

 
<h1>Добавление памяти</h1> 
<form action="processaddgroup.php" method="post"> 
<table border=0> 
<tr bgcolor=#cccccc> 
  <td width="150">        
 <td width="15"> 
 <tr> 
  <td>Размер памяти
  <td align="left"><input type="text" name="sizethatadds" size="30" maxlength="10"> 
 <tr> 
  <td col span="2" align="center"><input type="submit" value="Добавить"></td> 
</table> 
</form> 
        <p><a href='index.php'>К списку оборудования</a> 
</body> 
</html> 
  