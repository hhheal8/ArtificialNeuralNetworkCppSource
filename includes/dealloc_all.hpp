#ifndef DEALLOC_ALL_H
#define DEALLOC_ALL_H

template<typename ...ALL_VNARGS>
auto dealloc_all(ALL_VNARGS &...c_entity) -> void {
  ((delete c_entity), ...);
  ((c_entity = nullptr), ...);
}


#endif // DEALLOC_ALL_H