#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <json.hpp>

namespace scanner {    
    const int FPS_60 = 60,
            FPS_30 = 30;
            
    class config {
        private:
            struct calib_data {
                std::vector<double> K, D;
            };

            void to_json(nlohmann::json& j, const calib_data& data);
            void from_json(const nlohmann::json& j, calib_data& data);

        public:
            void save_calib(const cv::Mat& K, const cv::Mat& D);        
            void load_calib(cv::Mat& K, cv::Mat& D);        
    };
}