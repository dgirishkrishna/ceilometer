2. Edit the ``/etc/ceilometer/ceilometer.conf`` file and complete
   the following actions:

   * Configure Gnocchi connection:

     .. code-block:: ini

        [dispatcher_gnocchi]
        # filter out Gnocchi-related activity meters (Swift driver)
        filter_service_activity = False
        # default metric storage archival policy
        archive_policy = low

   * In the ``[DEFAULT]`` section,
     configure ``RabbitMQ`` message queue access:

     .. code-block:: ini

        [DEFAULT]
        ...
        transport_url = rabbit://openstack:RABBIT_PASS@controller

     Replace ``RABBIT_PASS`` with the password you chose for the
     ``openstack`` account in ``RabbitMQ``.

   * In the ``[service_credentials]`` section, configure service credentials:

     .. code-block:: ini

        [service_credentials]
        ...
        auth_type = password
        auth_url = http://controller:5000/v3
        project_domain_id = default
        user_domain_id = default
        project_name = service
        username = ceilometer
        password = CEILOMETER_PASS
        interface = internalURL
        region_name = RegionOne

     Replace ``CEILOMETER_PASS`` with the password you chose for
     the ``ceilometer`` user in the Identity service.

   * Create Ceilometer resources in Gnocchi. Gnocchi should be running by this
     stage:

     .. code-block:: console

        # ceilometer-upgrade --skip-metering-database
