#include <gtest/gtest.h>

#ifndef LANGCC_INCLUDE_PATH
#define LANGCC_INCLUDE_PATH ""
#endif

// Climbs directory tree until it finds the first match then returns abs path
inline std::filesystem::path resolvePath(const std::string &relPath) {
  auto baseDir = std::filesystem::current_path();
  while (baseDir.has_parent_path()) {
    auto combinePath = baseDir / relPath;
    if (std::filesystem::exists(combinePath)) {
      return combinePath;
    }
    if (baseDir == baseDir.parent_path()) {
      break;
    }
    baseDir = baseDir.parent_path();
  }
  throw std::runtime_error("File " + relPath + " not found!");
}
