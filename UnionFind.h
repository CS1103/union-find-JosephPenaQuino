#ifndef UNION_FIND_JOSEPHPENAQUINO_UNIONFIND_H
#define UNION_FIND_JOSEPHPENAQUINO_UNIONFIND_H

#include <vector>
namespace UTEC
{
    struct Data
    {
        Data * parent;
        int id;
        explicit Data(int id) : id{id}, parent{nullptr} {}

        bool operator << (const Data & in2)
        {
            return parent->id == in2.id;
        }
    };

    template <typename T>
    class UnionFind
    {
    private:
        int size;
        std::vector<Data*> data_set;
        void make_set(int id)
        {
            Data * new_data = new Data(id);
            data_set.push_back(new_data);
        }


    public:
        explicit UnionFind(int size) : size{size}
        {
            for (int i = 1; i <= size; ++i)
                make_set(i);
        }

        int find(int id)
        {
            if (id >= size)
                return 0;

            int parent_id = id;
            Data temp_data(0);
            temp_data = *data_set[parent_id-1];
            while (temp_data.parent != nullptr)
            {
                parent_id = temp_data.parent->id;
                temp_data = *data_set[parent_id-1];
            }

            return parent_id;
        }

        void join(int id1, int id2)
        {
            data_set[id1-1]->parent = data_set[id2-1];
        }

        Data &operator[] (int index)
        {
            if (index <= size)
                return *data_set[index-1];
        }
    };
}



#endif //UNION_FIND_JOSEPHPENAQUINO_UNIONFIND_H
