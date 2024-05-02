//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_MY_DATE_H
#define WORDS_MY_DATE_H

#include <ctime>
#include <string>

namespace words_memorization::utils {

    /**
     * �Զ������ʾ����
     */
    class myDate {
    private:
        int year;
        int month;
        int day;

    public:
        /**
         * Ĭ�Ϲ��캯��������ֻ����һ��
         */
        myDate();

        /**
         * ��ȡ���ڵ��ַ�����ʾ
         * @return YYYY-MM-DD
         */
        [[nodiscard]] std::string String() const;

        /**
         * ��ȡ������ʱ�� yyyy-mm-dd hh:mm:ss ������־ϵͳʹ��
         * @return std::string ʱ���ַ��� e.g. 2024.1.5 32:23:43
         */
        static std::string getFullTimeForLog();
    };

} // words_memorization
// utils

#endif //WORDS_MY_DATE_H
