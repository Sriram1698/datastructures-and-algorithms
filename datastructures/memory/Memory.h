#pragma once

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::unique_ptr;

template <typename T> using SharedPtr = std::shared_ptr<T>;

template <typename T> using UniquePtr = std::unique_ptr<T>;

template <typename T>
using EnableSharedFromThis = std::enable_shared_from_this<T>;

template <typename T, typename... Args>
static inline auto MakeShared(Args &&...args) {
  return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
static inline auto MakeUnique(Args &&...args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}