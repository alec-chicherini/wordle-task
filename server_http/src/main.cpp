#include <userver/components/minimal_server_component_list.hpp>
#include <userver/clients/dns/component.hpp>
#include <userver/clients/http/component.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/server/handlers/tests_control.hpp>
#include <userver/testsuite/testsuite_support.hpp>
#include <userver/utils/daemon_run.hpp>
#include <userver/components/fs_cache.hpp>

#include <http_handler_subdomain_static.hpp>

int main(int argc, char* argv[]) {
  auto component_list = userver::components::MinimalServerComponentList()
                            .Append<userver::server::handlers::Ping>()
                            .Append<userver::components::TestsuiteSupport>()
                            .Append<userver::components::HttpClient>()
                            .Append<userver::clients::dns::Component>()
                            .Append<userver::server::handlers::TestsControl>()
                            .Append<userver::components::FsCache>("repotest.ru")
                            .Append<userver::components::FsCache>("wordle-task.repotest.ru")
                            .Append<server_http::HttpHandlerSubdomainStatic>();

  return userver::utils::DaemonMain(argc, argv, component_list);
}
