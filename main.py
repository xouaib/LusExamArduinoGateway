import pymysql
from app import app
from db_config import mysql
from flask import jsonify
from flask import flash, request

# insert new recordedData			
@app.route('/create', methods=['POST'])
def insert_recordedData():
    try:
        _json = request.json
        _sensor_Id = _json['sensorId']
        _value = _json['value']
        
            # insert record in database
            sqlQuery = "INSERT INTO RecordedData(SensorId, Value) VALUES(%d, %d)"
            data = (_sensor_Id, _value)
            conn = mysql.connect()
            cursor = conn.cursor()
            cursor.execute(sqlQuery, data)
            conn.commit()
            res = jsonify('RecordedData created successfully.')
            res.status_code = 200

            return res
        else:
            return not_found()
    except Exception as e:
        print(e)
    finally:
        cursor.close() 
        conn.close()

# error handler
@app.errorhandler(404)
def not_found(error=None):
    message = {
        'status': 404,
        'message': 'There is no record: ' + request.url,
    }
    res = jsonify(message)
    res.status_code = 404

    return res
        
if __name__ == "__main__":
    app.run()	