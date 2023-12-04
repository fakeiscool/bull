from flask import *
from flask_login import *
from users import User
from bd import Database

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your_secret_key'

login_manager = LoginManager(app)

database = Database()
database.init()

@login_manager.user_loader
def load_user(user_id):
    return User.get(user_id)

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        user = database.authenticate_user(username, password)

        if user:
            login_user(user)
            return redirect(url_for('home'))

    return render_template('login.html')

@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('home'))

@app.route('/registration', methods=['GET', 'POST'])
def registration ():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        if database.authenticate_user(username, password) is None:
            database.register_user(username, password)

            return redirect(url_for('login'))

        return "Пользователь уже существует."

    return render_template('registration.html')


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
            return render_template('error.html', error_message=f"Ошибка в добавлении записи: {e}")

    memory_set_options = database.display_memory_set_ids()

    return render_template('add_pc_record.html', memory_set_options=memory_set_options)

# Добавление записи в таблицу memory_set
@app.route('/add_memory_set_record', methods=['GET', 'POST'])
@login_required
def add_memory_set_record():
    if request.method == 'POST':
        memory_size = request.form.get('memory_size')

        try:
            database.add_memory_set_record(memory_size)
            return redirect(url_for('display_memory_set'))
        except Exception as e:
            return render_template('error.html', error_message=f"Ошибка при добавлении записи Memory Set: {e}")

    return render_template('add_memory_set_record.html')
    
# Новый маршрут для отображения таблицы ПК
@app.route('/display_pc_table', methods=['GET', 'POST'])
def display_pc_table():
    table_headers = ["ID", "Рег. номер", "Проц. тип", "Размер диска", "Размер памяти"]
    result = database.display_pc_table()
    if request.method == 'POST': 
        memory_size = request.form.get('memory_size')

        if not memory_size or not memory_size.isnumeric():
            return render_template('pc_table.html', headers=[], data=[], search_result=None)
            
        result = database.display_pc_table(memory_size)
        
    try:
        if result:
            return render_template('pc_table.html', headers=table_headers, search_result=result)
        else:
            return render_template('pc_table.html', headers=table_headers, data=[], search_result=None)
    except Exception as e:
        return f"Ошибка в поиске по памяти: {e}"

        return f"Ошибка отображения таблицы PC: {e}"

# Новый маршрут для отображения таблицы Memory_set
@app.route('/display_memory_set', methods=['GET', 'POST'])
def display_memory_set():
    table_headers = ["ID", "Размер оперативной памяти"]
    result = database.display_memory_set_ids()
    if request.method == 'POST':
        mem_num = request.form.get('mem_num_size')

        if not mem_num or not mem_num.isnumeric():
            return render_template('memory_set_table.html', headers=[], data=[], search_result=None)
            
        result = database.display_memory_set_ids(mem_num)
        
    try:
        if result:
            return render_template('memory_set_table.html', headers=table_headers, search_result=result)
        else:
            return render_template('memory_set_table.html', headers=table_headers, data=[], search_result=None)
    except Exception as e:
        return f"Ошибка отображения таблицы memory_set: {e}"


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

@app.route('/edit_pc_record', methods=['GET', 'POST'])
@login_required
def edit_pc_record():
    if request.method == 'GET':
        pc_id = request.args.get('pc_id')

        # Получаем информацию о записи для предзаполнения формы
        pc_record = database.get_pc_record(pc_id)

        if pc_record:
            memory_set_options = database.display_memory_set_ids()
            return render_template('edit_pc_record.html', pc_record=pc_record, memory_set_options=memory_set_options)
        else:
            return render_template('error.html', error_message="Запись не найдена.")
    elif request.method == 'POST':
        # Обработка данных, отправленных при редактировании
        pc_id = request.form.get('pc_id')
        reg_num = request.form.get('reg_num')
        processor_type = request.form.get('processor_type')
        disk_size = request.form.get('disk_size')
        memory_size = request.form.get('memory_size')

        try:
            database.edit_pc_record(pc_id, reg_num, processor_type, disk_size, memory_size)
            return redirect(url_for('display_pc_table'))
        except Exception as e:
            return render_template('error.html', error_message=f"Ошибка при редактировании записи: {e}")


if __name__ == '__main__':
    app.run(debug=True)
