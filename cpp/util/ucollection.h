#ifndef _UTIL_COLLECTION
#define _UTIL_COLLECTION

namespace UCollection {

  template<typename T> 
  void add(T& dest, const T& src) {
    for (auto& item: src) {
      dest.push_back(item);
    }
  };


  template<typename K, typename V>
  void set(std::map<K,V>& map_, const K& k_, const V& v_) {
    typename std::map<K,V>::iterator it = map_.find(k_);
    if (it==map_.end()) {
      map_.insert(std::pair<K,V>(k_, v_));
    } else {
      it->second = v_;
    }    
  }


  template<typename K, typename V>
  V getValue(const std::map<K,V>& map_, const K& k_, V default_) {
    typename std::map<K,V>::const_iterator it = map_.find(k_);
    if (it!=map_.end()) {
      //printf("getValue %d\n", it->second);
      return it->second;
    }

    return default_;
  }


};

#endif
