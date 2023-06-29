#include "rclcpp/rclcpp.hpp"
#include "apply_zyz_rotation/srv/get_zyz_rotation.hpp"                                       // CHANGE

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 4) { // CHANGE
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: get_zyz_rotation_client Z1 Y Z2");      // CHANGE
      return 1;
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("get_zyz_rotation_client");  // CHANGE
  rclcpp::Client<apply_zyz_rotation::srv::GetZyzRotation>::SharedPtr client =                // CHANGE
    node->create_client<apply_zyz_rotation::srv::GetZyzRotation>("zyz_rotation");          // CHANGE

  auto request = std::make_shared<apply_zyz_rotation::srv::GetZyzRotation::Request>();       // CHANGE
  request->z1 = atoll(argv[1]);
  request->y  = atoll(argv[2]);
  request->z2 = atoll(argv[3]);                                                              // CHANGE

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result_future = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result_future) !=
    rclcpp::FutureReturnCode::SUCCESS)
  {  
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service get_zyz_rotation");    // CHANGE
    return -1;
  }

  auto result = result_future.get();
  RCLCPP_INFO(
    node->get_logger(), "\nR=" "\n\t%.3f\t"  "%.3f\t" "%.3f" "\n\t%.3f\t"  "%.3f\t" "%.3f" "\n\t%.3f\t"  "%.3f\t" "%.3f\n",
    result->r[0], result->r[1], result->r[2], result->r[3], result->r[4], result->r[5], result->r[6], result->r[7], result->r[8]);

  rclcpp::shutdown();
  return 0;
}
