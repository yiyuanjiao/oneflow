#ifndef ONEFLOW_CORE_COMMON_LAYOUT_STANDARDIZE_H_
#define ONEFLOW_CORE_COMMON_LAYOUT_STANDARDIZE_H_

namespace oneflow {

template<typename T>
class LayoutStandardize final {
 public:
  void __Init__() { new (&data_[0]) T(); }
  void __Delete__() { mut_data()->~T(); }

  const T& Get() const { return *reinterpret_cast<const T*>(&data_[0]); }
  T* Mutable() { return reinterpret_cast<T*>(&data_[0]); }

 private:
  union {
    char data_[sizeof(T)];
    int64_t align_;
  };
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_COMMON_LAYOUT_STANDARDIZE_H_
