#include <string>

namespace AbstractOperation{
    class AbstractOperation{
    private:
        std::string m_operation;
        std::string m_inputFiles;
        std::string m_outputFile; 
        CacheManager m_cacheManager;


    public:
            /**
             * @brief Construct a new Abstract Operation object
             * 
             * @param m_operation - operation
             * @param m_inputFiles - input files of operation
             * @param m_outputFile - output file 
             * @param m_cacheManager - cache manager object
             */
           AbstractOperation(std::string m_operation, std::string m_inputFiles, std::string m_outputFile, CacheManager m_cacheManager);

            /**
             * @brief The function check if the parameters are appopriate
             * 
             * @return true - parameters are appopriate
             * @return false - parameters are not appopriate
             */
            virtual void checkParameters() const = 0;

            /**
             * @brief The function do the operation of the user
             * 
             */
            virtual void doOperation() const = 0;

            const std::string getOperation() const;

            const std::string getInputFiles() const;

            const std::string getOutputFile() const;
    };
}