#ifndef fgengine_lazy_delete_vector_hpp
#define fgengine_lazy_delete_vector_hpp
#include <vector>
#include <algorithm>
#include <pic-gl/Util/tools.hpp>

namespace picppgl{

template <class t>
class lazyDeleteVector{
    public:
        typedef std::vector<t> storage;
    private:
        storage collection;
        storage erase;
    public:
        void add(t element){collection.push_back(element);}
        void element_delete(t element){erase.push_back(element);}
        void realDelete(){
            for(auto i=erase.begin();i!=erase.end();++i){
                auto o=std::find(collection.begin(), collection.end(), *i);
                collection.erase(o);
            }
            erase.clear();
        }
        storage& data(){return collection;};
};

}
#endif