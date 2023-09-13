add_subdirectory(sequential)

execute_process(COMMAND python ${PROJECT_SOURCE_DIR}/scripts/generate_nums.py 10000)