/**
 * @file src/statements/SpawnStatement.cpp
 * @brief Implements SpawnStatement.
 */
#include <iostream>
#include <thread>
#include <process.h>
#include "../variables/Variables.hpp"
#include "SpawnStatement.hpp"
#include "Statement.hpp"

/**
* @brief The statement to run inside a thread.
*
* @param statement The statement.
*/
void ExecuteStatement(Statement *statement) { statement->Execute(); }

/**
* @brief C++ Thread to execute the function.
*/
// void SpawnStatement::Execute() const {
//   std::thread t(ExecuteStatement, statement);
//   t.join();
// }
void SpawnStatement::Execute() const {
    _beginthread((void(*)(void*))ExecuteStatement, 0, statement);
}

/**
* @brief Loads the statements and assign to Token and Statement.
*
* @param program The tokenizer to understand next steps and eat some tokens.
*/
void SpawnStatement::Read(Tokenizer &program) {
  Token spawn = program.GetToken();
  statement = Statement::GetNext(program);
}
