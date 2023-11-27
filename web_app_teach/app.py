from flask import *
from flask_login import *
from werkzeug.security import *

from bd import *
from users import *

import sqlite3
app = Flask(__name__)
app.config['SECRET_KEY'] = 'based_secret_key'




login_manager = LoginManager(app)

database = Database()



@login_manager.user_loader
def load_user(user_id):
    return User.get(user_id)

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        user = database.authenticate_user(username, password)

        if user:
            login_user(user)
            return redirect(url_for('display_pc_table'))

    return render_template('login.html')



@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('display_pc_table'))


@app.route('/restricted')
@login_required
def restricted():
    return render_template('restricted.html', username=current_user.username)       
            
            
@app.route('/')
def home():
    return render_template('base.html')
    
@app.route('/display_pc_table', methods=['GET', 'POST'])
def display_pc_table():
    if request.method == 'POST':
        memory_size = request.form.get('memory_size')

        if not memory_size or not memory_size.isnumeric():
            return render_template('pc_table.html', headers=[], data=[], search_result=None)


        try:
            result = database.display_pc_table(memory_size)
            if result:
                table_headers = ["ID", "Рег. номер", "Проц. тип", "Размер диска", "Размер памяти"]
                return render_template('pc_table.html', headers=table_headers, search_result=result)
        except Exception as e:
            return f"Ошибка в поиске по памяти: {e}"
    try:
        result = database.display_pc_table()
        if result:
            table_headers = ["ID", "Рег. номер", "Проц. тип", "Размер диска", "Размер памяти"]
            return render_template('pc_table.html', headers=table_headers, data=result, search_result=None)
    except Exception as e:
        return f"Ошибка отобржаения таблицы PC: {e}"
        

@app.route('/delete_pc_record', methods=['POST'])
@login_required
def delete_pc_record():
    pc_id = request.form.get('pc_id')

    try:
        database.delete_pc_record(pc_id)
        return redirect(url_for('display_pc_table'))
    except Exception as e:
        return f"Ошибка в удалении записи: {e}"
        

@app.route('/delete_memory_set_record', methods=['POST'])
@login_required
def delete_memory_set_record():
    memory_set_id = request.form.get('memory_set_id')

    try:
        database.delete_memory_set_record(memory_set_id)
        return redirect(url_for('display_memory_set'))
    except Exception as e:
        return f"Ошибка в удалении записи: {e}"
        

@app.route('/add_pc_record', methods=['GET', 'POST'])
@login_required
def add_pc_record():
    if request.method == 'POST':
        reg_num = request.form.get('reg_num')
        processor_type = request.form.get('processor_type')
        disk_size = request.form.get('disk_size')
        memory_size = request.form.get('memory_size')

        try:
            database.add_pc_record(reg_num, processor_type, disk_size, memory_size)
            return redirect(url_for('display_pc_table'))
        except Exception as e:
            return f"Ошибка в добавлении записи: {e}"

    memory_set_options = database.get_memory_set_options()

    return render_template('add_pc_record.html', memory_set_options=memory_set_options)
        
@app.route('/display_memory_set', methods=['GET', 'POST'])
def display_memory_set():
    if request.method == 'POST':
        num = request.form.get('num')

        if not num or not num.isnumeric():
            return render_template('memory_set_table.html', headers=[], data=[], search_result=None)
        try:
            
            result = database.display_memory_set_ids(num)
            if result:
                table_headers = ["ID", "Memory Set Num"]
                return render_template('memory_set_table.html', headers=table_headers, search_result=result)
        except Exception as e:
            return f"Ошибка в поиске числа в таблице memory_set: {e}"


    try:
        result = database.display_memory_set_ids()
        if result:
            table_headers = ["ID", "Memory Set Num"]
            return render_template('memory_set_table.html', headers=table_headers, data=result, search_result=None)
    except Exception as e:
        return f"Ошибка в отображении таблицы memory_set: {e}"




            
@app.route('/add_memory_set_record', methods=['GET', 'POST'])
@login_required
def add_memory_set_record():
    if request.method == 'POST':
        num = request.form.get('num')

        if not num or not num.isnumeric():
            return "Неправильно введеное число."

        try:
            database.add_memory_set_record(num=num)
            return redirect(url_for('display_memory_set'))
        except Exception as e:
            return f"Ошибка отображения таблицы: {e}"

    return render_template('add_memory_set_record.html')


if __name__ == '__main__':
    
    database.init()
    app.run(debug=True)