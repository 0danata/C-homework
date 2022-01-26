#pragma once
#include <cassert> // ��� assert()

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) {}

    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    // ����� ��������� ������� ������� � ���������� ��� ����� �� 0
    void erase()
    {
        delete[] m_data;
        // ����� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
        m_data = nullptr;
        m_length = 0;
    }
    // ���������� ��������� ����������.
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // ������� reallocate() �������� ������ �������. ��� ������������ �������� ������ ������� ����� ����������. ������� �������
    void reallocate(int newLength)
    {
        // ������� ��� ������������ �������� ������ �������
        erase();

        // ���� ��� ������ ������ ���� ������, �� ��������� ������� �����
        if (newLength <= 0)
            return;

        // ����� �������� ����� ��������
        m_data = new int[newLength];
        m_length = newLength;
    }

    // ������� resize() �������� ������ �������. ��� ������������ �������� �����������. ������� ���������
    void resize(int newLength)
    {
        // ���� ������ ������ �����, �� ��������� return
        if (newLength == m_length)
            return;

        // ���� ����� ������� ������ ������, �� ������ ��� � ����� ��������� return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // ������ �����������, ��� newLength �������, �� ������� ����, �� ������ ��������. ����������� ��������� �������� ��������:
        // 1. �������� ����� ������.
        // 2. �������� �������� �� ������������� ������� � ��� ������ ��� ���������� ������.
        // 3. ���������� ������ ������ � ���� ������� m_data ��������� �� ����� ������.

        // �������� ����� ������
        int* data = new int[newLength];

        // ����� ��� ����� ����������� � ����������� ���������� ��������� � ����� ������.
        // ��� ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // ���������� �������� ��������
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // ������� ������ ������, ��� ��� �� ��� ��� �� �����
        delete[] m_data;

        // � ���������� ������ ������� ������� �����! �������� ��������, m_data ��������� �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������.
        // ��������� ������ ���� ����������� ��������, �� ��� �� ����� ����������, ����� ������ �� ������� ���������
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // �������� ������������ ������������� �������
        assert(index >= 0 && index <= m_length);

        // ������� ����� ������ �� ���� ������� ������ ������� �������
        int* data = new int[m_length + 1];

        // �������� ��� �������� �� �� index
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // ��������� ��� ����� ������� � ��� ����� ������
        data[index] = value;

        // �������� ��� �������� ����� ������������ ��������
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // ������� ������ ������ � ���������� ������ ���� ����� ������
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void remove(int index)
    {
        // �������� �� ������������ ������������� �������
        assert(index >= 0 && index < m_length);

        // ���� ��� ��������� ������� �������, �� ������ ������ ������ � ��������� return
        if (m_length == 1)
        {
            erase();
            return;
        }

        // C������ ����� ������ �� ���� ������� ������ ������ ������� �������
        int* data = new int[m_length - 1];

        // �������� ��� �������� �� �� index
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // �������� ��� �������� ����� ���������� ��������
        for (int after = index + 1; after < m_length; ++after)
            data[after - 1] = m_data[after];

        // ������� ������ ������ � ���������� ������ ���� ����� ������
        delete[] m_data;
        m_data = data;
        --m_length;
    }
    void Push_pop(int value) { insertBefore(value, 0); }
    void Push_back(int value) { insertBefore(value, m_length); }


    //1. �������� � ������������ �����, ������� ��� ������� � ���� �����, ������:
    //� ��� �������� ���������� �������� �������(������ ������� pop_back() � ��������)
    //    � ��� �������� ������� �������� �������(������ pop_front() � ��������)
    //    � ��� ���������� �������
    //    � ��� ������ �� ����� ���������.
    void Pop_back()
    {
        resize(m_length - 1);
    }
    void Pop_front()
    {
        int* data = new int[--m_length];

        for (int index = 1; index < m_length; ++index)
            data[index - 1] = m_data[index];

        delete[] m_data;
        m_data = data;
        --m_length;
    }
    void PrintArr()
    {
        for (size_t i = 0; i < getLength(); i++)
        {
            std::cout << m_data[i] << " " ;
        }
        std::cout << std::endl;
    }
    void insert_sort()
    {
        int temp, pos;
        for (size_t i = 1; i < m_length; i++)
        {
            temp = m_data[i];
            pos = i - 1;
            while (pos >= 0 && m_data[pos] > temp)
            {
                m_data[pos + 1] = m_data[pos];
                pos--;
            }
            m_data[pos + 1] = temp;
        }
    }



    int getLength() { return m_length; }
};
