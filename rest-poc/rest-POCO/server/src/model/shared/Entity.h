//
// Created by avictoria on 1/02/23.
//

#ifndef SERVER_MODEL_ENTITY_H
#define SERVER_MODEL_ENTITY_H

#include <string>
#include "IEntity.h"

namespace Model {
    namespace Shared {

        class Entity : public IEntity {
        public:
            Entity();

            explicit Entity(const std::string &);

            virtual ~Entity() = 0;

            std::string identity() const final;

            bool operator==(const IEntity &) final;

            bool operator!=(const IEntity &) final;

        private:
            const std::string _identity;

        };

    }
}

#endif //SERVER_MODEL_ENTITY_H
