#include "Domain/UI/UI/UI.h"
#include "Domain/Cafe/Cafe.h"
#include "Domain/Menu/Menu.h"
#include "Domain/Data/Data.h"
#include "Domain/UI/Logger/Logger.h"

int main() {
    // Create shared pointers to the necessary objects
    auto menu = std::make_shared<Menu>();  // Use std::make_shared
    auto data = std::make_shared<Data>();  // Use std::make_shared
    auto cafe = std::make_shared<Cafe>(menu, data);  // Pass shared_ptrs to Cafe
    auto logger = std::make_shared<Logger>();  // Create shared pointer to Logger
    
    // Create UI instance with shared pointers to Cafe and Logger
    UI ui(cafe, logger);  // Now UI constructor can accept shared_ptrs

    // Run the UI
    ui.run();

    return 0;
}
