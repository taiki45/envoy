#pragma once

#include <string>

namespace Envoy {
/**
 * Wraps compiled in code versioning.
 */
class VersionInfo {
public:
  // Version number (e.g. 1.6.0). Refer VERSION file.
  static const std::string& versionNumber();
  // Repository revision (e.g. git SHA1).
  static const std::string& revision();
  // Repository status (e.g. clean, modified).
  static const std::string& revisionStatus();
  // Repository information and build type.
  static std::string version();
};
} // namespace Envoy
