//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_MYDATE_H
#define WORDS_MYDATE_H

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
    };

} // words_memorization
// utils

#endif //WORDS_MYDATE_H
