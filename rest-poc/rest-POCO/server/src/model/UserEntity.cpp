//
// Created by avictoria on 1/02/23.
//

#include "UserEntity.h"

namespace Model {
    namespace UserManagement {

        UserEntity::UserEntity()
                : Entity(),
                  _name(),
                  _email(),
                  _image(),
                  _createdAt() {
            // it may include some initial validations...
        }

        UserEntity::UserEntity(
                const std::string &id,
                const std::string &_name,
                const std::string &_email,
                const std::string &_image,
                Poco::DateTime createdAt
        )
                : Entity(id),
                  _name(_name),
                  _email(_email),
                  _image(_image),
                  _createdAt(createdAt) {
            // it may include some initial validations...
        }

        std::string UserEntity::getName() const {
            return _name;
        }

        void UserEntity::setName(const std::string &name) {
            _name = name;
        }

        std::string UserEntity::getEmail() const {
            return _email;
        }

        void UserEntity::setEmail(const std::string &email) {
            _email = email;
        }

        std::string UserEntity::getImage() const {
            return _image;
        }

        void UserEntity::setImage(const std::string &image) {
            _image = image;
        }

        Poco::DateTime UserEntity::getCreatedAt() const {
            return _createdAt;
        }

    }
}