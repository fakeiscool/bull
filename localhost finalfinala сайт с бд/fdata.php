<?php 


function testdata($reg_num, $model_code, $processor_type, $memory_size, $disk_size){
 
    $error='Ошибка: ';
    
	if (strlen($reg_num)==0) {$error .='Вы не ввели рег номер <br>'; }
	if (strlen($model_code)==0) {$error .='Вы не ввели номер модели <br>'; }
	if (strlen($processor_type)==0) {$error .='Вы не ввели тип процессора <br>'; }
	if (strlen($memory_size)==0) {$error .='Вы не ввели кол-во памяти <br>'; }
	if (strlen($disk_size)==0) {$error .='Вы не ввели размер диска <br>'; }
	
	return $error; 

}


?>