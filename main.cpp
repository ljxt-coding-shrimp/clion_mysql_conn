#include <iostream>
#include <mysql.h>
#include <windows.h>
using namespace std;
int main() {
    MYSQL *conn = mysql_init(NULL); // ��ʼ��
    if(nullptr != conn){
        MYSQL *pMysql = mysql_real_connect(conn, "127.0.0.1", "root", "xiami", "blog", 3306, nullptr, 0); // ��ȡ���ݿ�����
        mysql_set_character_set(pMysql,"gb2312"); // ���ñ���
        if(nullptr!=pMysql){
            int query_result = mysql_query(pMysql, "select * from article"); // ��ѯ���ݿ�
            MYSQL_RES *pRes = mysql_store_result(pMysql); // ׼����������
            MYSQL_ROW row;
            unsigned int len = mysql_num_fields(pRes); // ��ȡ����ֶγ���
            while((row = mysql_fetch_row(pRes))){ // ����һ������
                for (int i = 0; i < len; ++i) { // ���������е�����
                    char* msg = row[i]; // ��ȡһ������
                    if(nullptr!=msg){ // �жϵõ������Ƿ�Ϊ��
                        cout << row[i]; // �������
                    }
                     cout << "\t" ; // ��������
                }
                cout << endl; // ����
            }
            mysql_free_result(pRes); // �ͷ����ݴ洢
        }
    }
    mysql_close(conn); // �ر����ݿ���
    cout << "\n\n���ݿ���Խ���." << endl;
    system("pause");
    return 0;
}