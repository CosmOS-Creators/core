#include <gmock/gmock.h>

#include "stack_mock.h"

#include "stack.h"

// instantiate mocked lib
std::unique_ptr<Stack_MOCK> Stack_TestFixture::_StackMock;

// fake lib functions
void stackInit_init(CosmOS_CoreVariableType * coreVar)
{
    Stack_TestFixture::_StackMock->stackInit_init(coreVar);
}
