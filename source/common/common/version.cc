#include "common/common/version.h"

#include <string>

#include "common/common/macros.h"

#include "fmt/format.h"

extern const char build_version[];
extern const char build_scm_revision[];
extern const char build_scm_status[];

namespace Envoy {
const std::string& VersionInfo::versionNumber() {
  CONSTRUCT_ON_FIRST_USE(std::string, build_version);
}
const std::string& VersionInfo::revision() {
  CONSTRUCT_ON_FIRST_USE(std::string, build_scm_revision);
}
const std::string& VersionInfo::revisionStatus() {
  CONSTRUCT_ON_FIRST_USE(std::string, build_scm_status);
}

std::string VersionInfo::version() {
  return fmt::format("{}/{}/{}/{}", versionNumber(), revision(), revisionStatus(),
#ifdef NDEBUG
                     "RELEASE"
#else
                     "DEBUG"
#endif
  );
}
} // namespace Envoy
