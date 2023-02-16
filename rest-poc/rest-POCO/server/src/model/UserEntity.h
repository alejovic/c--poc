//
// Created by avictoria on 1/02/23.
//

#ifndef SERVER_MODEL_USERENTITY_H
#define SERVER_MODEL_USERENTITY_H

#include "shared/Entity.h"
#include <Poco/DateTime.h>

namespace Model {
    namespace UserManagement {

        class UserEntity final : public Shared::Entity {
        public:
            /// User-defined Default Constructor
            UserEntity();

            /*!
             * @param identity      The unique identity of the User.
             * @param name
             * @param email
             * @param image
             * @param createdAt     Date and time the vote was made.
             */
            explicit UserEntity(const std::string &identity,
                                const std::string &_name,
                                const std::string &_email,
                                const std::string &_image,
                                Poco::DateTime createdAt = Poco::DateTime());

            std::string getName() const;
            void setName(const std::string &);

            std::string getEmail() const;
            void setEmail(const std::string &);

            std::string getImage() const;
            void setImage(const std::string &);

            Poco::DateTime getCreatedAt() const;

            // Assignment Operator returns by value for supporting immutability.
            UserEntity operator=(const UserEntity &);

        private:
            std::string _name;
            std::string _email;
            std::string _image;
            const Poco::DateTime _createdAt;

        };

    }
}

#endif //SERVER_MODEL_USERENTITY_H
