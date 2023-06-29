#include "rclcpp/rclcpp.hpp"
#include "apply_zyz_rotation/srv/get_zyz_rotation.hpp"

#include <memory>
#include <cmath>

# define M_PI 3.14159265358979323846  // pi

void rotate(const std::shared_ptr<apply_zyz_rotation::srv::GetZyzRotation::Request> request,
          std::shared_ptr<apply_zyz_rotation::srv::GetZyzRotation::Response>     response)
{
  double z1 = (request->z1)*M_PI/180;	// recebe o valor em graus e converte em radianos
  double y = (request->y)*M_PI/180;
  double z2 = (request->z2)*M_PI/180;
  
  // sequencia de preenchimento: da primeira linha, para a segunda e, por fim, para a terceira
  response->r[0] = cos(z1)*cos(y)*cos(z2) -sin(z1)*sin(z2);
  response->r[1] = -1*(cos(z2)*cos(y)*sin(z1) + sin(y)*cos(z2));
  response->r[2] = cos(z2)*sin(y);

  response->r[3] = cos(z1)*cos(y)*sin(z2) + sin(z1)*cos(z2);
  response->r[4] = -sin(z1)*sin(z2)*cos(y) + cos(z2)*cos(z1);
  response->r[5] = sin(z2)*sin(y);

  response->r[6] = -sin(y)*cos(z1);
  response->r[7] = sin(y)*sin(z1);
  response->r[8] = cos(y);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response");
  //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
  //              request->a, request->b);
  //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("apply_zyz_rotation_server");

  rclcpp::Service<apply_zyz_rotation::srv::GetZyzRotation>::SharedPtr service =
    node->create_service<apply_zyz_rotation::srv::GetZyzRotation>("zyz_rotation", &rotate);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to rotate.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}
